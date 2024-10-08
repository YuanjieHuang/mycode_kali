#导入模拟仿真需要的库
import tensorflow as tf
import numpy as np

#导入可视化需要的库
import PIL.Image
from io import StringIO
from io import BytesIO
from IPython.display import clear_output, Image, display

tf.compat.v1.disable_eager_execution()
def DisplayArray(a, fmt='jpeg', rng=[0,1]): #用于表示池塘表面状态
  """Display an array as a picture."""
  a = (a - rng[0])/float(rng[1] - rng[0])*255
  a = np.uint8(np.clip(a, 0, 255))
  f = BytesIO()
  PIL.Image.fromarray(a).save(f, fmt)
  display(Image(data=f.getvalue()))

sess = tf.compat.v1.InteractiveSession()

def make_kernel(a):
#   '''Transform a 2D array into a convolution kernel'''
  a = np.asarray(a)
  a = a.reshape(list(a.shape) + [1,1])
  return tf.constant(a, dtype=1)

def simple_conv(x, k):
  """A simplified 2D convolution operation"""
  x = tf.expand_dims(tf.expand_dims(x, 0), -1)
  y = tf.nn.depthwise_conv2d(x, k, [1, 1, 1, 1], padding='SAME')
  return y[0, :, :, 0]

def laplace(x):
  """Compute the 2D laplacian of an array"""
  laplace_k = make_kernel([[0.5, 1.0, 0.5],
                           [1.0, -6., 1.0],
                           [0.5, 1.0, 0.5]])
  return simple_conv(x, laplace_k)
# 创建一个完美的 500 × 500 的正方形池塘
N = 500

# Initial Conditions -- some rain drops hit a pond

# Set everything to zero
u_init = np.zeros([N, N], dtype="float32")
ut_init = np.zeros([N, N], dtype="float32")

# Some rain drops hit a pond at random points
for n in range(40):
  a,b = np.random.randint(0, N, 2)
  u_init[a,b] = np.random.uniform()

DisplayArray(u_init, rng=[-0.1, 0.1])

# Parameters:
# eps -- time resolution
# damping -- wave damping
eps = tf.compat.v1.placeholder(tf.float32, shape=())
damping = tf.compat.v1.placeholder(tf.float32, shape=())

# Create variables for simulation state
U  = tf.Variable(u_init)
Ut = tf.Variable(ut_init)

# Discretized PDE update rules
U_ = U + eps * Ut
Ut_ = Ut + eps * (laplace(U) - damping * Ut)

# Operation to update the state
step = tf.group(
  U.assign(U_),
  Ut.assign(Ut_))

# Initialize state to initial conditions
tf.compat.v1.initialize_all_variables().run()

# Run 1000 steps of PDE
for i in range(1000):
  # Step simulation
  step.run({eps: 0.03, damping: 0.04})
  # Visualize every 50 steps
  if i % 50 == 0:
    clear_output()
    DisplayArray(U.eval(), rng=[-0.1, 0.1])



# merged_summary_op = tf.merge_all_summaries()
# summary_writer = tf.train.SummaryWriter('/tmp/mnist_logs', sess.graph)
# total_step = 0
# while training:
#   total_step += 1
#   session.run(training_op)
#   if total_step % 100 == 0:
#     summary_str = session.run(merged_summary_op)
#     summary_writer.add_summary(summary_str, total_step)