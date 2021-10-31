# import tensorflow as tf
# # Create TensorFlow object called hello_constant
# hello_constant = tf.constant('Hello World!')
# tf.compat.v1.disable_eager_execution()
# with tf.compat.v1.Session() as sess:
#     # Run the tf.constant operation in the session
#     output = sess.run(hello_constant)
#     print(output)

import tensorflow as tf

#创建一个Tensor字符串常量
hello = tf.constant("hello world ")
print(hello)

test = tf.constant('hello 世界')
print(test)
print(test.numpy())
print(test.numpy().decode())

# Create two variables.
weights = tf.Variable(tf.random_normal([784, 200], stddev=0.35),
                      name="weights")
biases = tf.Variable(tf.zeros([200]), name="biases")
# Add an op to initialize the variables.
init_op = tf.initialize_all_variables()

# Later, when launching the model
with tf.Session() as sess:
  # Run the init operation.
  sess.run(init_op)
  # Use the model

# Create a variable with a random value.
weights = tf.Variable(tf.random_normal([784, 200], stddev=0.35),
                      name="weights")
# Create another variable with the same value as 'weights'.
w2 = tf.Variable(weights.initialized_value(), name="w2")
# Create another variable with twice the value of 'weights'
w_twice = tf.Variable(weights.initialized_value() * 0.2, name="w_twice")
# Add an op to initialize the variables.
init_op = tf.initialize_all_variables()

# Add ops to save and restore all the variables.
saver = tf.train.Saver()
# Save the variables to disk.
save_path = saver.save(sess, "/tmp/model.ckpt")
print "Model saved in file: ", save_path

# Later, launch the model, use the saver to restore variables from disk, and
# do some work with the model.
with tf.Session() as sess:
  # Restore variables from disk.
  saver.restore(sess, "/tmp/model.ckpt")
  print "Model restored."
  # Do some work with the model