
local alias_seq = tonumber(redis.call('HGET', '__u:UserAliasList:UserAlias', ARGV[1]))
if alias_seq <= 0 then
	return {err='invaild alias seq:'..alias_seq}
end

local result = {}

local pc = redis.call('HMGET', 'UserAliasList:'..alias_seq, 
	'Flag',
	'UserId',
	'UserSeq',
	'AliasSeq',
	'Race',
	'Job',
	'Body',
	'Rank',
	'Level',
	'Exp',
	'Sp',
	'SkillExp',
	'Gold',
	'RealmPoint',
	'LostExp',
	'Ns',
	'NsCharge',
	'Hp',
	'Sta',
	'Mp',
	'TitleId',
	'Region',
	'PosX',
	'PosY',
	'BindRegion',
	'BindPosX',
	'BindPosY',
	'TransRegion',
	'TransPosX',
	'TransPosY',
	'LogSp', 
	'GuildSeq',
	'QuickBar',
	'PetInfo',
	'SkillBuffTime',
	'Teleport',
	'Summon',
	'TameMob')

if pc[1] ~= '1' then
	return redis.error_reply('UserAlias has been deleted:'..alias_seq)
elseif pc[2] ~= ARGV[2] then
	return redis.error_reply('UserId not match:'..pc[1]..'~='..ARGV[2])
elseif pc[3] ~= ARGV[3] then
	return redis.error_reply('UserSeq not match:'..pc[1]..'~='..ARGV[3])
end

	
if pc[28] ~= '0' and pc[28] ~= pc[22] then		    --if (pc->m_btTransRegion) and 
	pc[22] = pc[28] 		--pc->m_btRegion = pc->m_btTransRegion;
	pc[23] = pc[29]			--pc->m_cell = pc->m_cellTrans;
	pc[24] = pc[30]			
	pc[28] = '0'
	pc[29] = '0'
	pc[30] = '0'
end

table.insert(result, pc)

local friend_array = {}
local friend_list = redis.call('smembers', 'FriendList:'..alias_seq)
for i=1,#(friend_list) do
	local friend_useralias = redis.call('HGET', 'UserAliasList:'..friend_list[i], 'UserAlias')
	if not friend_useralias then
		return {err='invailed UserAliasList:'..friend_list[i]}
	end
	
	table.insert(friend_array, {friend_list[i], friend_useralias})
end
table.insert(result, friend_array)

if pc[22] ~= ARGV[4] and ARGV[5] == '1' then --pc->m_btRegion != world_manager->m_btRegion && IsMainServer
	return result
end

table.insert(result, redis.call('HGETALL', 'SkillList:'..alias_seq))

local item_list = redis.call('SMEMBERS', '__s:ItemList:AliasSeq:'..alias_seq)
local item_array = {}
for i=1,#(item_list) do
	local item = redis.call('HMGET', 'ItemList:'..item_list[i],
		'AliasSeq','UserSeq','ItemId','ItemName','Pos','Rare','Count',
		'AttackMinDamage','AttackMaxDamage','DefenseDamage','UniqueSeq','Option')
	if tonumber(item[1]) ~= alias_seq or item[2] ~= '0' then
		return {err='invaild item owner seq:'..item_list[i]}
	end
		
	table.insert(item, 3, item_list[i])
	table.insert(item_array, item);
end
table.insert(result, item_array)
	
table.insert(result, redis.call('HVALS', 'QuestList:'..alias_seq))

table.insert(result, redis.call('SMEMBERS','TitleList:'..alias_seq))

return result




