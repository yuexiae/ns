local result = redis.call('SREM', '__s:ItemList:AliasSeq:'..ARGV[1], ARGV[2])
redis.call('RENAME', 'ItemList:'..ARGV[2], '__d:ItemList:'..ARGV[2])
return result