if redis.call('SMOVE', '__s:ItemList:UserSeq:'..ARGV[2],
	'__s:ItemList:AliasSeq:'..ARGV[1], ARGV[3]) ~= 1 then
	return {err='smove failed'}
end

redis.call('HMSET', 'ItemList:'..ARGV[3], 'AliasSeq', ARGV[1], 'UserSeq', '0', 'Pos', ARGV[4])

return redis.status_reply('OK')