local alias_seq
if ARGV[1] == '0' then
	alias_seq = tonumber(redis.call('HGET', '__u:UserAliasList:UserAlias', ARGV[2]))
	if alias_seq <= 0 then
		return {err='invaild alias seq:'..alias_seq}
	end
else
	alias_seq = ARGV[2]
end

local guild_seq = redis.call('HGET', 'UserAliasList:'..alias_seq, 'GuildSeq')
if guild_seq ~= ARGV[3] then
	return redis.error_reply('guild_seq ~= ARGV[3]')
end

redis.call('SREM', '__s:UserAliasList:GuildSeq:'..ARGV[3], alias_seq)
redis.call('HMSET', 'UserAliasList:'..alias_seq, 'GuildSeq', '0', 'GuildRank', '0')
return redis.status_reply('OK')