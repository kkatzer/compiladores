program Pforward(input, output);

procedure Later  (a: integer); forward;

procedure Sooner (var b :integer);
begin
  Later (b);
end;

procedure Later(a :integer);
begin
  Sooner (a);
end;

begin
   Later (4);
end.
