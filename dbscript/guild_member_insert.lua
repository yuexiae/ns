local guild_seq = redis.call('HGET', 'UserAliasList:'..ARGV[2], 'GuildSeq')
if guild_seq ~= '0' then
	return redis.error_reply('UserAliasList:'..ARGV[2]..' already join in a guild')
end


redis.call('HMSET', 'UserAliasList:'..ARGV[2], 'GuildSeq', ARGV[1], 'GuildRank', ARGV[3])
redis.call('SADD', '__s:UserAliasList:GuildSeq:'..ARGV[1], ARGV[2])

return redis.status_reply('OK')