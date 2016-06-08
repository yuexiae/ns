local result = {}
local members = redis.call('smembers', '__s:UserAliasList:GuildSeq:'..ARGV[1])
for i=1,#(members) do
	local member_info = redis.call('HMGET', 'UserAliasList:'..members[i], 'GuildSeq', 'UserAlias', 'GuildRank')
	if member_info[1] ~= ARGV[1] then
		return {err='invailed member info'.. members[i]}
	end
	
	member_info[1] = members[i]
	table.insert(result, member_info)
end
return result