local members = redis.call('smembers', '__s:UserAliasList:GuildSeq:'..ARGV[1])
for i=1,#(members) do
	if redis.call('EXISTS', 'UserAliasList:'..members[i]) == 1 then
		redis.call('HMSET', 'UserAliasList:'..members[i], 'GuildSeq', 0, "GuildRank", 0)
	end
end

redis.call('DEL', '__s:UserAliasList:GuildSeq:'..ARGV[1])
redis.call('SREM', '__s:GuildList', ARGV[1])
redis.call('DEL', 'GuildList:'..ARGV[1])

return redis.status_reply('OK')