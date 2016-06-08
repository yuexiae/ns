local total_level = 0
local members = redis.call('smembers', '__s:UserAliasList:GuildSeq:'..ARGV[1])
for i=1,#(members) do
	total_level = total_level + tonumber(redis.call('HGET', 'UserAliasList:'..members[i], 'Level'))
end
return total_level