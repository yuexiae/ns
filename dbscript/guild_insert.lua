if table.getn(ARGV) ~= 4 then
	return {err='table size error'}
end

local Seq = redis.call('HINCRBY', '__c', 'GuildList', "1")
if Seq > 2147483647 then
	return {err='invailed seq:'..Seq }
end

if redis.call('EXISTS', 'GuildList:'..Seq) == 1 then
	return {err='GuildList:'..Seq..' exists'}
end

redis.call('HMSET', 'GuildList:'..Seq,
	'AliasSeq', ARGV[1],
	'Realm', ARGV[2],
	'GuildName', ARGV[3],
	'Comment', ARGV[4],
	'Level', 0,
	'Point', 0,
	'RankMonth', 0,
	'Mark', 0,
	'Rank', 0,
	'RankPoint', 0,
	'MarkData', ''
	)
	
redis.call('SADD', '__s:GuildList', Seq)

return Seq