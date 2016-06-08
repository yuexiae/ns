local UserId = string.lower(ARGV[1])

if redis.call('EXISTS', 'UserList:'..UserId) == 1 then
	return 0
end

local Seq = redis.call('HINCRBY', '__c', 'UserList', "1")

redis.call('HMSET', 'UserList:'..UserId,
	'Seq', Seq,
	'ConnData', 0,
	'PcBangCheck', 0,
	'Gear', 0,
	'RegDate', 0)

redis.call('HSET', '__u:UserList:Seq', UserId, Seq)

return 1