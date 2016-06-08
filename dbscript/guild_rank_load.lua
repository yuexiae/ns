local result = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
local guild_list = redis.call('SMEMBERS', '__s:GuildList')
for i=1,#(guild_list) do
	if tonumber(guild_list[i]) ~= nil then
		local guild_info = redis.call('HMGET', 'GuildList:'..guild_list[i], 'Realm', 'RankMonth')
		if tonumber(guild_info[1]) == tonumber(ARGV[1]) and tonumber(guild_info[2]) >= 1 and tonumber(guild_info[2]) <= 10 then
			result[tonumber(guild_info[2])] = tonumber(guild_list[i])
		end
	end
end
return result