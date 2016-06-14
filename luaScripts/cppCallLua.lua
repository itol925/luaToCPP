function printHelloWorld()
	print("hello world!");
end

function printHelloSomebody(sb)
	print("hello "..sb);
end

function sortNum(n1, n2)
	local tmp;
	if n1 > n2 then
		tmp = n1;
		n1 = n2;
		n2 = tmp;
	end
	return n1, n2;		
end