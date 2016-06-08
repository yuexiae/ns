local list = redis.call('SMEMBERS', '__s:UserAliasList:UserId:'..ARGV[1])
for i=1,#(list) do
	local result = redis.call('HMGET', 'UserAliasList:'..list[i], 'UserId', 'Flag', 'Race')
	if result[1] == ARGV[1] and result[2] == '1' then 
		return tonumber(result[3])
	end 
end
return 0
