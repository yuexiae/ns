local reply = redis.call('HMGET', 'UserInfo:'..ARGV[1], 'Realm', 'Gold')
if not reply[1] or not reply[2] then
	redis.call('HMSET', 'UserInfo:'..ARGV[1], 'Realm', ARGV[2], 'Gold', '0')
	return 0
elseif reply[1] ~= ARGV[2] then
	redis.call('HMSET', 'UserInfo:'..ARGV[1], 'Realm', ARGV[2], 'Gold', '0')

	local list = redis.call('SMEMBERS', '__s:ItemList:UserSeq:'..ARGV[1])
	for i=1,#(list) do
		redis.call('RENAME', 'ItemList:'..list[i], '__d:ItemList:'..list[i])
	end
	redis.call('DEL', '__s:ItemList:UserSeq:'..ARGV[1])
	return 0
else
	return tonumber(reply[2])
end