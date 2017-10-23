function theta= ackerman(x)
%x is de rack travel in mm
%+ als rack naar rechts beweegt van achter de wagen bekeken
%- als rack naar links beweegt van achter de wagen bekeken

thetaL=-2*(10^-9)*(x^6)+8*(10^-8)*(x^5)+9*(10^-7)*(x^4)+3*(10^-5)*(x^3)-0.0049*(x^2)+1.0437*x+0.0254;
%thetaL is hoeverdraaiing van linker wiel in °
%-hoek is draaien naar links van boven de wagen bekeken
%+hoek is draaien naar rechts van boven de wagen bekeken

thetaR=2*(10^-9)*(x^6)+8*(10^-8)*(x^5)-9*(10^-7)*(x^4)+3*(10^-5)*(x^3)+0.0049*(x^2)+1.0437*x-0.0254;
%thetaR is hoekverdraaiing van rechter wiel in °
%-hoek is draaien naar links van boven de wagen bekeken
%+hoek is draaien naar rechts van boven de wagen bekeken

theta=[thetaL; thetaR];

end

