function current = testParser(Mux,status,messageNr,valueHigh,valueLow)
%    format hex;
    valueHigh = swapbytes(typecast(valueHigh,'uint16'));
    valueLow = swapbytes(typecast(valueLow,'uint16'));
    current=0;
    %0 is current
%     disp (Mux);
%     disp (status);
%     disp (messageNr);
%     disp (valueHigh);
%     disp (valueLow);
    value = [valueHigh,valueLow];
%     disp (value);
    if Mux==0
        if status==0
            %status ok
            current = swapbytes(typecast(value,'uint32'));%current in mA
        else
        end
    end
%     disp (current);
%     format long;
%     disp (current);
end