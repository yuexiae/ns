if redis.call('HEXISTS', '__u:UserAliasList:UserAlias', ARGV[1]) == 1 then
	return 0
end

local Seq = redis.call('HINCRBY', '__c', 'UserAliasList', '1')
if Seq > 2147483647 then
	return { err='Seq too long:'..Seq }
end

if redis.call('EXISTS', 'UserAliasList:'..Seq) == 1 then
	return {err='UserAliasList:'..Seq..' exists'}
end


redis.call('HSET', '__u:UserAliasList:UserAlias', ARGV[1], Seq)


redis.call('HMSET', 'UserAliasList:'..Seq,
	'AliasSeq', Seq,
	'Flag', 1,
	'UserAlias', ARGV[1],
	'UserSeq', ARGV[2],
	'UserId', ARGV[3],
	'Race', ARGV[4],
	'Job', ARGV[5],
	'Body', ARGV[6],
	'Level', 1,
	'SkillExp', 0,
	'Region', ARGV[7],
	'PosX', ARGV[8],
	'PosY', ARGV[9],
	'BindRegion', ARGV[7],
	'BindPosX', ARGV[8],
	'BindPosY', ARGV[9],
	'RegDate', ARGV[10],
	'Ns', 0,
	'NsCharge', 0,
	'Hp', 0,
	'Sta', 0,
	'Mp', 0,
	'Exp', 0,
	'Sp', 0,
	'Gold', 0,
	'TransRegion', 0,
	'TransPosX', 0,
	'TransPosY', 0,
	'LogSp', 0,
	'LastDate', 0,
	'Rank', 0,
	'RealmPoint', 0,
	'LostExp', 0,
	'TitleId', 0,
	'QuickBar', ARGV[11],
	'SkillBuffTime', '',
	'PetInfo', '',
	'Summon', '',
	'TameMob', '',
	'Teleport', '',
	'GuildSeq', 0,
	'GuildRank', 0
)

redis.call('SADD', '__s:UserAliasList:UserId:'..ARGV[3], Seq)
redis.call('SADD', '__s:UserAliasList:UserSeq:'..ARGV[2], Seq)


return Seq