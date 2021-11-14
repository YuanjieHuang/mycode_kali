import redis
   
'''r = redis.Redis(host='127.0.0.1', port=6379)
r.set('foo', 'Bar')
print((r.get('foo')))
'''
pool = redis.ConnectionPool(host='127.0.0.1', port=6379)
r = redis.Redis(connection_pool=pool)
r.set('foo', 'Bar')
print(r.get('foo'))