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

timeTable;

obj1 = instrfind('Type', 'serial', 'Port', 'COM4', 'Tag', '');
obj2 = instrfind('Type', 'serial', 'Port', 'COM6', 'Tag', '');

if isempty(obj1)
    obj1 = serial('COM4','BAUD',9600);
else
    fclose(obj1);
    obj1 = obj1(1)
end
if isempty(obj2)
    obj2 = serial('COM6','BAUD',9600);
else
    fclose(obj2);
    obj2 = obj2(1)
end

fopen(obj1);
fopen(obj2);

set(obj1, 'Terminator', {13,13});
set(obj1, 'Timeout', 10.0);
set(obj2, 'Terminator', {13,13});
set(obj2, 'Timeout', 10.0);

tic
for x=1:100
% Communicating with instrument object, obj1.
timeTable(x,1) = toc;
fprintf(obj1, 'Time Test Master');
data = fscanf(obj1);
timeTable(x,2) = toc;
pause(.5);

end

endTime = toc;

% Disconnect all objects.
fclose(obj1);

% Clean up all objects.
delete(obj1);

