local Seq = redis.call('HINCRBY', '__c', 'ItemList', '1')
if Seq > 2147483647 then
	return {err='invailed seq:'..Seq }
end

if redis.call('EXISTS', 'ItemList:'..Seq) == 1 then
	return {err='ItemList:'..Seq..' exists'}
end

redis.call('HMSET', 'ItemList:'..Seq,
	'AliasSeq', ARGV[1],
	'UserSeq', 0,
	'ItemId', ARGV[2],
	'ItemName', ARGV[3],
	'Pos', ARGV[4],
	'Rare', ARGV[5],
	'Count', ARGV[6],
	'AttackMinDamage', ARGV[7],
	'AttackMaxDamage', ARGV[8],
	'DefenseDamage', ARGV[9],
	'UniqueSeq', ARGV[10],
	'Option', ARGV[11]
	)
	
redis.call('SADD', '__s:ItemList:AliasSeq:'..ARGV[1], Seq)

return Seq