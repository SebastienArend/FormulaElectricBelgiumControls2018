function [messageByte0,messageByte1,messageByte2,messageByte3, messageByte4, messageByte5, messageByte6,messageByte7,progress] = setupEM(initialProgress)
    progress = initialProgress;
    messageValue = uint8(zeros(1,8));
    if (progress<5)
        if(progress==0)
            messageValue(1) = uint8(52); %0x34 set_mode --> stop
            messageValue(2:8)= uint8(zeros(1,7));
            progress=1;
        elseif(progress==1)
            messageValue(1) = uint8(33); %0x21 set configuration of U1
            messageValue(2) = uint8(2); %0x02 cyclisch && big endian
            messageValue(3:4) = uint8([0 50]); %50ms 
            messageValue(5:8) = zeros(1,4);
            progress=2;
        elseif(progress==2)
            messageValue(1) = uint8(37); %0x25 set configuration of W
            messageValue(2) = uint8(2); %0x02 cyclisch && big endian
            messageValue(3:4) = uint8([0 50]); %50ms 
            messageValue(5:8) = zeros(1,4);
            progress = 3;
        elseif(progress ==3)
            messageValue(1) = uint8(38); %0x26 set configuration of As
            messageValue(2) = uint8(2); %0x02 cyclisch && big endian
            messageValue(3:4) = uint8([0 50]); %50ms 
            messageValue(5:8) = zeros(1,4);
            progress = 4;
        elseif (progress ==4)
            messageValue(1) = uint8(52); %0x34 set_mode--> start
            messageValue(2:3) = uint8(ones(1,2));
            messageValue(4:8) = zeros(1,5);
            progress=5;
        end
        messageByte0 = messageValue(1);
        messageByte1 = messageValue(2);
        messageByte2 = messageValue(3);
        messageByte3 = messageValue(4);
        messageByte4 = messageValue(5);
        messageByte5 = messageValue(6);
        messageByte6 = messageValue(7);
        messageByte7 = messageValue(8);
        disp(messageValue(1:4));
    end
end
            