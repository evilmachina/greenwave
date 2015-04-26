//
// Copyright 2014, Andreas Lundquist
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// LightBlue Bean - Basic
//                                               version: 1.0 - 2014-10-28
//
// This implementation makes it possible to connect to a LightBlue Bean
// and control the LED. It also fetches the temperature from the board.
//
// The LightBlue Bean needs to run the arduino sketch example named
// LightBlue Bean - Basic

// Route all console logs to Evothings studio log
if (window.hyper) { console.log = hyper.log; }

document.addEventListener('deviceready',function(){ app.initialize() }, false);

var app = {};

app.UUID_SCRATCHSERVICE = 'a495ff20-c5b1-4b44-b512-1370f02d74de';

app.getScratchCharacteristicUUID = function(scratchNumber) {

	return ['a495ff21-c5b1-4b44-b512-1370f02d74de',
			'a495ff22-c5b1-4b44-b512-1370f02d74de',
			'a495ff23-c5b1-4b44-b512-1370f02d74de',
			'a495ff24-c5b1-4b44-b512-1370f02d74de',
			'a495ff25-c5b1-4b44-b512-1370f02d74de'][scratchNumber - 1];
};

app.initialize = function() {
	
	app.showInfo("Initialize");
	app.connected = false;
	app.connect();
	$('body').addClass('initialized');
}

app.deviceIsLightBlueBeanWithBleId = function(device, bleId) {

	return ((device != null) && (device.name != null) && (device.name == bleId));
};

app.connect = function(user)
{
	var BLEId = "Green Wave";
	app.showInfo('Trying to connect to "' + BLEId +'"');
	
	app.disconnect(user);

	function onScanSuccess(device) {

		function onConnectSuccess(device) {

			function onServiceSuccess(device) {

				// Update user interface
				app.showInfo('Connected to <i>' + BLEId + '</i>');
				setTimeout(function(){
					setMessage();
				}, 3000);
				// document.getElementById('BLEButton').innerHTML = 'Disconnect';
				// document.getElementById('BLEButton').onclick = new Function('app.disconnect()');
				// document.getElementById('ledControl').style.display = 'block';
				// document.getElementById('temperatureDisplay').style.display = 'block';

				// Application is now connected
				app.connected = true;
				app.device = device;

			};

			function onServiceFailure(errorCode) {

				// Show an error message to the user
				app.showInfo('Error reading services: ' + errorCode);
			};

			// Connect to the appropriate BLE service
			device.readServices([app.UUID_SCRATCHSERVICE], onServiceSuccess, onServiceFailure);
		};

		function onConnectFailure(errorCode) {

			// Show an error message to the user
			app.showInfo('Error ' + errorCode);
		};

		console.log('device.name =' + device.name);

		// Connect if we have found a LightBlue Bean with the name from input (BLEId)
		if (app.deviceIsLightBlueBeanWithBleId(device, BLEId)) {

			// Update user interface
			app.showInfo('Found "' + device.name + '"');

			// Stop scanning
			easyble.stopScan();

			// Connect to our device
			app.showInfo('Identifying service for communication');
			device.connect(onConnectSuccess, onConnectFailure);
		};
	};
	function onScanFailure(errorCode) {

		// Show an error message to the user
		app.showInfo('Error: ' + errorCode);
		easyble.stopScan();
	};

	// Update the user interface
	app.showInfo('Scanning...');
	

	// Start scanning for devices
	easyble.startScan(onScanSuccess, onScanFailure);
};

app.disconnect = function(user) {

	// If timer configured, clear.
	if (app.interval) {

		clearInterval(app.interval);
	}

	app.connected = false;
	app.device = null;

	// Hide user inteface
	// document.getElementById('ledControl').style.display = 'none';
	// document.getElementById('temperatureDisplay').style.display = 'none';

	// Stop any ongoing scan and close devices.
	easyble.stopScan();
	easyble.closeConnectedDevices();

	// Update user interface
	app.showInfo('Not connected');
	// document.getElementById('BLEButton').innerHTML = 'Connect';
	// document.getElementById('BLEButton').onclick = new Function('app.connect()');
};


app.sendStatus = function(data){
	if (app.connected) {
		var data = new Uint8Array([data, 0, 0]);
		function onDataWriteSuccess() {

			console.log('Succeded to write data.');
		}

		function onDataWriteFailure(errorCode){

			console.log('Failed to write data with error: ' + errorCode);
			app.disconnect();
		};

		app.writeDataToScratch(1, data, onDataWriteSuccess, onDataWriteFailure);
	}
};


app.writeDataToScratch = function(scratchNumber, data, succesCallback, failCallback) {

	if(app.connected) {

		console.log('Trying to write data to scratch ' + scratchNumber);
		app.device.writeCharacteristic(app.getScratchCharacteristicUUID(scratchNumber), data, succesCallback, failCallback);
	}
	else {

		console.log('Not connected to device, cant write data to scratch.');
	};
};



app.showInfo = function(info) {

	//console.log(info)
	//document.getElementById('BLEStatus').innerHTML = info;
	setMessage(info);
};
