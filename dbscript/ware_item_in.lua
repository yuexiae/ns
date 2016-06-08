if redis.call('SMOVE', '__s:ItemList:AliasSeq:'..ARGV[1],
	'__s:ItemList:UserSeq:'..ARGV[2], ARGV[3]) ~= 1 then
	return {err='smove failed'}
end

redis.call('HMSET', 'ItemList:'..ARGV[3], 'AliasSeq', '0', 'UserSeq', ARGV[2], 'Pos', ARGV[4], 'Count', ARGV[5])

return redis.status_reply('OK')