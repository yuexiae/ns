if redis.call('EXISTS', 'UserAliasList:'..ARGV[1]) ~= 1 then
	return redis.error_reply('UserAliasList:'..ARGV[1]..' not exists')
end

if redis.call('HEXISTS', '__u:UserAliasList:UserAlias', ARGV[3]) == 1 then
	return 0
end

if redis.call('HDEL', '__u:UserAliasList:UserAlias', ARGV[2]) ~= 1 then
	return redis.error_reply('__u:UserAliasList:UserAlias '..ARGV[2]..' not exists')
end

redis.call('HSET', '__u:UserAliasList:UserAlias', ARGV[3], ARGV[1])
redis.call('HSET', 'UserAliasList:'..ARGV[1], 'UserAlias', ARGV[3])

return 1