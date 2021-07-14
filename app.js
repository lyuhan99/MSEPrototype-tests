//run server
const express = require('express');  // include the "express" module
const app = express();
const path = require('path');
const port = 3000;

// Define route for get request at '/'
//app.get('/', (req, res) => res.send('hello, express world'));
app.get('/', function (req, res) {
    res.sendFile(path.join(__dirname, '/public/index.html'));
});
// Define the static resource (HTML/CSS/JS/images)
app.use(express.static('public'));             // URL '/' (root) maps to 'public' directory
app.use('/img', express.static('public'));  // URL '/img' also maps to 'public' directory

const server = app.listen(port, () => console.log(`Server listening at port ${port}...`));


//--------arduino stuff---------------//

var SerialPort = require('serialport');
const parsers = SerialPort.parsers;

const parser = new parsers.Readline({
    delimiter: '\r\n'
});

//specify location of the serial port! 
var serialPort = new SerialPort('COM5', {
    baudRate: 9600,
    dataBits: 8,
    parity: 'none',
    stopBits: 1,
    flowControl: false
});

serialPort.pipe(parser);

//-------------Listening for the data to send from the website----------//
const io = require('socket.io')(server);

io.on('connection', function(socket) {
    
    console.log('Node is listening to port');
    //message is the name of the message specified on the html page
    socket.on('message',function(data){
        
        console.log( data );
        //data.status is the string that is being passed to the arduino
        serialPort.write( data.status );
    
    });
    
});

parser.on('data', function(data) {
    
    console.log('Received data from port: ' + data);
    io.emit('data', data);
    
});

//References
//https://www.youtube.com/watch?v=hFBFju_ZSYs&ab_channel=AdamThomas
//prof chua's website omg


