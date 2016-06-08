local cost_gear = tonumber(ARGV[2])
if cost_gear < 0 then 
	return {err = 'invailed cost gear'..ARGV[2]}
end 

local gear = tonumber(redis.call('HGET', 'UserList:'..ARGV[1], 'Gear'))
if not gear then
	return -102
end 

local remaining_gear = gear - cost_gear
if remaining_gear < 0 then
	return -103
end

gear = tonumber(redis.call('HINCRBY', 'UserList:'..ARGV[1], 'Gear', -cost_gear))
if gear ~= remaining_gear then
	return -102
end

return 1