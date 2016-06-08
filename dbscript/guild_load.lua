local result = redis.call('HMGET', 'GuildList:'..ARGV[1],
		'AliasSeq', 'Realm', 'GuildName', 'Comment', 'Level', 'Point', 'RankMonth', 'Mark', 'Rank', 'RankPoint', 'MarkData')

result[1] = redis.call('HGET', 'UserAliasList:'..result[1], 'UserAlias')

return result
