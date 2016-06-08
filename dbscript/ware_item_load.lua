local list = redis.call('SMEMBERS', '__s:ItemList:UserSeq:'..ARGV[1])
local item_array = {}
for i=1,#(list) do
	local item = redis.call('HMGET', 'ItemList:'..list[i],
		'AliasSeq','UserSeq','ItemId','ItemName','Pos','Rare','Count',
		'AttackMinDamage','AttackMaxDamage','DefenseDamage','UniqueSeq','Option')
	if item[1] ~= '0' or item[2] ~= ARGV[1] then
		return {err='invaild item owner:'..list[i]}
	end
		
	table.insert(item, 3, list[i])
	table.insert(item_array, item);
end
return item_array