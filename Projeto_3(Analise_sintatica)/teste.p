program exFunction;
var
   a, b, ret : integer;
   var d : real;
(*function definition *)
function max(num1, num2: integer; d: real): integer;
var
   (* local variable declaration *)
   result: integer;
begin
   writeln('d value: ', d);
   if (num1 > num2) then
      result := num1
   else
      result := num2;
   max := result;
end;
begin
   a := 100;
   b := 200;
   d := 22.20;
  (* calling a function to get max value *)
   ret := max(a, b, d);
   writeln( 'Max value is : ', ret );
end.