if redis.call('EXISTS', 'GuildList:'..ARGV[1]) ~= 1 then
	return {err='GuildList:'..Seq..' not exists'}
end

local alias_seq = tonumber(redis.call('HGET', '__u:UserAliasList:UserAlias', ARGV[2]))
if alias_seq <= 0 then
	return {err='invaild alias seq:'..alias_seq}
end

redis.call('HMSET', 'GuildList:'..ARGV[1],
	'AliasSeq', alias_seq,
	'GuildName', ARGV[3],
	'Comment', ARGV[4],
	'Level', ARGV[5])
	
return redis.status_reply('OK')