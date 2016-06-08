local list = redis.call('SMEMBERS', '__s:UserAliasList:UserId:'..ARGV[1])
table.sort(list, function(a,b) return tonumber(a) < tonumber(b) end) 

local result = {}
for i=1,#(list) do
	local data = redis.call('HMGET', 'UserAliasList:'..list[i], 'AliasSeq','Flag','UserAlias','Race','Job','Body','Level','Region','PosX','PosY','TransRegion','TransPosX','TransPosY')
	
	if data[1] == list[i] and data[2] == '1' then
		local item_array = {}
		local item_list = redis.call('SMEMBERS', '__s:ItemList:AliasSeq:'..list[i])
		for index,item_seq in ipairs(item_list) do
			local item = redis.call('HMGET', 'ItemList:'..item_seq, 'Pos', 'ItemId')
			if tonumber(item[1]) > 0 and tonumber(item[1]) < 67 then
				table.insert(item_array, item[1] * 65536 + item[2])
			end
		end
		
		table.insert(data, item_array);
		table.insert(result, data);
	end
end

return result