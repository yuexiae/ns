local alias_seq = tonumber(redis.call('HGET', '__u:UserAliasList:UserAlias', ARGV[1]))
if alias_seq <= 0 then
	return {err='invaild alias seq:'..alias_seq}
end

local result = redis.call('HMGET', 'UserAliasList:'..alias_seq, 'UserId', 'GuildSeq')
if result[1] ~= ARGV[2] then
	return redis.error_reply(user_id..' ~= '..ARGV[2])
end

if result[2] ~= '0' then
	return 2
end

redis.call('HSET', 'UserAliasList:'..alias_seq, 'Flag', '255')
return 1