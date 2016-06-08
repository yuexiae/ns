local seq = tonumber(redis.call('HGET', '__u:UserAliasList:UserAlias', ARGV[2]))
if seq <= 0 then
	return {err='invaild alias seq:'..seq}
end

redis.call('SADD', 'FriendList:'..ARGV[1], seq)
return seq