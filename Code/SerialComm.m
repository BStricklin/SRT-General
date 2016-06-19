%SERIALCOMM Code for communicating with an instrument.
%
%   This is the machine generated representation of an instrument control
%   session. The instrument control session comprises all the steps you are
%   likely to take when communicating with your instrument. These steps are:
%   
%       1. Create an instrument object
%       2. Connect to the instrument
%       3. Configure properties
%       4. Write and read data
%       5. Disconnect from the instrument
% 
%   To run the instrument control session, type the name of the file,
%   SerialComm, at the MATLAB command prompt.
% 
%   The file, SERIALCOMM.M must be on your MATLAB PATH. For additional information 
%   on setting your MATLAB PATH, type 'help addpath' at the MATLAB command 
%   prompt.
% 
%   Example:
%       serialcomm;
% 
%   See also SERIAL, GPIB, TCPIP, UDP, VISA, BLUETOOTH, I2C, SPI.
% 
 
%   Creation time: 24-Feb-2016 04:42:41

% Find a serial port object.
obj1 = instrfind('Type', 'serial', 'Port', 'COM4', 'Tag', '');

% Create the serial port object if it does not exist
% otherwise use the object that was found.
if isempty(obj1)
    obj1 = serial('COM4');
else
    fclose(obj1);
    obj1 = obj1(1)
end

% Connect to instrument object, obj1.
fopen(obj1);

% Configure instrument object, obj1.
set(obj1, 'Terminator', {13,13});
% Configure instrument object, obj1.
set(obj1, 'Timeout', 10.0);

% Communicating with instrument object, obj1.
fprintf(obj1, 'This is how to write');
data1 = fscanf(obj1);
fprintf(obj1, 'This is how to write again');

% Disconnect all objects.
fclose(obj1);

% Clean up all objects.
delete(obj1);

