if redis.call('EXISTS', 'ItemList:'..ARGV[1]) ~= 1 then
	return {err='ItemList:'..ARGV[1]..' not exists'}
end

redis.call('HMSET', 'ItemList:'..ARGV[1], 'Pos', ARGV[2], 'Count', ARGV[3])

return redis.status_reply('OK')