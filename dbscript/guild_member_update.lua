local alias_seq
if ARGV[1] == '0' then
	alias_seq = tonumber(redis.call('HGET', '__u:UserAliasList:UserAlias', ARGV[2]))
	if alias_seq <= 0 then
		return {err='invaild alias seq:'..alias_seq}
	end
else
	alias_seq = ARGV[2]
end

redis.call('HMSET', 'UserAliasList:'..alias_seq, 'GuildRank', ARGV[3])
return redis.status_reply('OK')