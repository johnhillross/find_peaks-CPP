# find_peaks-CPP
Translate 'scipy.signal.find_peaks' into C++
# See more detail 'scipy.signal.find_peaks' in:
https://docs.scipy.org/doc/scipy/reference/generated/scipy.signal.find_peaks.html

---

# Comparison

## scipy.signal.find_peaks:

```python
import numpy as np
from scipy.signal import find_peaks
import matplotlib.pyplot as plt

x = np.array([-1.22,-1.225,-1.24,-1.245,-1.225,-1.215,-1.23,-1.245,-1.245,-1.215,-1.19,-1.185,-1.2,-1.205,-1.205,-1.195,-1.18,-1.165,-1.15,-1.165,-1.135,-1.09,-1.09,-1.09,-1.095,-1.075,-1.025,-0.975,-0.92,-0.885,-0.845,-0.795,-0.73,-0.65,-0.545,-0.455,-0.41,-0.385,-0.36,-0.335,-0.25,-0.195,-0.145,-0.085,-0.01,0.045,0.135,0.195,0.225,0.25,0.25,0.225,0.185,0.13,0.09,0.045,0.015,0.,0.025,0.03,0.,-0.055,-0.075,-0.085,-0.085,-0.055,-0.06,-0.09,-0.14,-0.21,-0.305,-0.43,-0.575,-0.775,-0.955,-1.095,-1.21,-1.3,-1.37,-1.425,-1.435,-1.435,-1.455,-1.47,-1.51,-1.54,-1.56,-1.585,-1.57,-1.56,-1.55,-1.565,-1.595,-1.6,-1.605,-1.625,-1.635,-1.655,-1.655,-1.68,-1.67,-1.675,-1.695,-1.725,-1.735,-1.73,-1.74,-1.745,-1.745,-1.75,-1.755,-1.765,-1.76,-1.765,-1.785,-1.795,-1.815,-1.815,-1.825,-1.825,-1.835,-1.845,-1.855,-1.84,-1.815,-1.815,-1.83,-1.845,-1.82,-1.79,-1.765,-1.735,-1.745,-1.76,-1.76,-1.71,-1.685,-1.665,-1.665,-1.65,-1.625,-1.59,-1.53,-1.475,-1.455,-1.45,-1.44,-1.41,-1.36,-1.335,-1.34,-1.36,-1.35,-1.325,-1.3,-1.27,-1.255,-1.25,-1.23,-1.22,-1.21,-1.215,-1.225,-1.225,-1.23,-1.21,-1.2,-1.205,-1.21,-1.2,-1.2,-1.18,-1.17,-1.165,-1.185,-1.185,-1.19,-1.185,-1.155,-1.165,-1.165,-1.155,-1.17,-1.175,-1.16,-1.16,-1.17,-1.18,-1.175,-1.15,-1.13,-1.12,-1.125,-1.13,-1.14,-1.135,-1.11,-1.11,-1.11,-1.125,-1.12,-1.105,-1.1,-1.095,-1.1,-1.11,-1.125,-1.115,-1.08,-1.06,-1.075,-1.08,-1.085,-1.075,-1.06,-1.05,-1.06,-1.08,-1.08,-1.055,-1.065,-1.055,-1.055,-1.065,-1.065,-1.06,-1.045,-1.04,-1.035,-1.045,-1.055,-1.04,-1.025,-1.02,-1.02,-1.045,-1.05,-1.03,-1.01,-0.99,-0.98,-0.98,-0.965,-0.945,-0.925,-0.905,-0.91,-0.915,-0.89,-0.87,-0.87,-0.845,-0.84,-0.855,-0.86,-0.865,-0.845,-0.84,-0.855,-0.885,-0.9,-0.91,-0.925,-0.95,-0.97,-0.995,-1.015,-1.01,-0.995,-0.995,-1.02,-1.03,-1.025,-1.01,-1.02,-1.03,-1.03,-1.045,-1.03,-1.02,-1.01,-1.005,-1.02,-1.03,-1.035,-1.025,-1.01,-1.015,-1.02,-1.04,-1.03,-1.03,-1.,-0.98,-0.925,-0.845,-0.71,-0.52,-0.27,0.005,0.26,0.455,0.555,0.49,0.245,-0.115,-0.495,-0.82,-0.955,-0.97,-0.97,-0.985,-1.01,-1.01,-0.975,-0.94,-0.945,-0.97,-1.,-1.,-0.985,-0.965,-0.95,-0.975,-0.98,-0.995,-0.995,-0.995,-0.97,-0.94,-0.945,-0.985,-0.98,-0.975,-0.98,-0.98,-0.965,-0.955,-0.95,-0.955,-0.94,-0.925,-0.905,-0.915,-0.91,-0.905,-0.9,-0.885,-0.89,-0.905,-0.905,-0.875,-0.87,-0.87,-0.87,-0.865,-0.85,-0.82,-0.8,-0.775,-0.785,-0.8,-0.815,-0.8,-0.755,-0.735,-0.73,-0.735,-0.74,-0.705,-0.67,-0.655,-0.66,-0.67,-0.675,-0.66,-0.635,-0.61,-0.59,-0.595,-0.595,-0.59,-0.57,-0.565,-0.58,-0.595,-0.585,-0.56,-0.52,-0.515,-0.51,-0.535,-0.56,-0.57,-0.575,-0.57,-0.575,-0.595,-0.625,-0.64,-0.605,-0.62,-0.655,-0.72,-0.745,-0.74,-0.71,-0.705,-0.745,-0.795,-0.825,-0.81,-0.82,-0.8,-0.825,-0.845,-0.875,-0.895,-0.875,-0.86,-0.86,-0.855,-0.84,-0.84,-0.86,-0.89,-0.895,-0.905,-0.875,-0.845,-0.84,-0.865,-0.89,-0.91,-0.91,-0.9,-0.885,-0.895,-0.875,-0.855,-0.87,-0.875,-0.875,-0.86,-0.85,-0.865,-0.85,-0.83,-0.815,-0.815,-0.835,-0.835,-0.845,-0.825,-0.81,-0.795,-0.795,-0.77,-0.75,-0.725,-0.71,-0.7,-0.715,-0.705,-0.71,-0.72,-0.7,-0.695,-0.7,-0.72,-0.715,-0.73,-0.735,-0.75,-0.78,-0.82,-0.815,-0.825,-0.825,-0.82,-0.835,-0.865,-0.87,-0.87,-0.875,-0.875,-0.875,-0.87,-0.87,-0.87,-0.875,-0.88,-0.875,-0.865,-0.865,-0.845,-0.845,-0.84,-0.85,-0.855,-0.86,-0.86,-0.88,-0.92,-0.94,-0.915,-0.825,-0.705,-0.55,-0.385,-0.215,0.,0.265,0.51,0.69,0.74,0.605,0.265,-0.095,-0.405,-0.66,-0.795,-0.85,-0.87,-0.875,-0.88,-0.83,-0.81,-0.81,-0.83,-0.84,-0.83,-0.825,-0.83,-0.86,-0.91,-0.915,-0.9,-0.865,-0.83,-0.85,-0.87,-0.87,-0.85,-0.82,-0.815,-0.83,-0.845,-0.85,-0.83,-0.805,-0.785,-0.785,-0.78,-0.76,-0.745,-0.725,-0.73,-0.73,-0.73,-0.735,-0.715,-0.705,-0.68,-0.68,-0.69,-0.68,-0.635,-0.625,-0.62,-0.61,-0.58,-0.57,-0.545,-0.53,-0.52,-0.52,-0.53,-0.525,-0.485,-0.45,-0.44,-0.445,-0.445,-0.44,-0.41,-0.375,-0.36,-0.375,-0.385,-0.395,-0.365,-0.35,-0.355,-0.39,-0.44,-0.45,-0.46,-0.425,-0.4,-0.425,-0.445,-0.465,-0.47,-0.495,-0.49,-0.53,-0.55,-0.54,-0.535,-0.545,-0.58,-0.62,-0.645,-0.655,-0.65,-0.655,-0.655,-0.655,-0.665,-0.68,-0.685,-0.685,-0.7,-0.7,-0.715,-0.72,-0.71,-0.68,-0.675,-0.675,-0.685,-0.69,-0.675,-0.675,-0.655,-0.675,-0.68,-0.67,-0.66,-0.66,-0.665,-0.685,-0.7,-0.705,-0.7,-0.685,-0.695,-0.7,-0.69,-0.695,-0.68,-0.655,-0.645,-0.64,-0.625,-0.62,-0.615,-0.6,-0.57,-0.545,-0.525,-0.535,-0.52,-0.49,-0.455,-0.465,-0.485,-0.49,-0.465,-0.435,-0.425,-0.405,-0.38,-0.32,-0.27,-0.18,-0.12,-0.08,-0.045,0.025,0.12,0.195,0.28,0.345,0.415,0.49,0.57,0.65,0.73,0.8,0.825,0.79,0.73,0.675,0.66,0.63,0.57,0.52,0.49,0.475,0.445,0.385,0.345,0.285,0.255,0.26,0.255,0.21,0.14,0.06,-0.025,-0.135,-0.275,-0.48,-0.67,-0.8,-0.885,-0.945,-0.965,-0.99,-1.01,-1.05,-1.07,-1.065,-1.07,-1.105,-1.14,-1.175,-1.165,-1.155,-1.175,-1.18,-1.205,-1.225,-1.22,-1.225,-1.235,-1.26,-1.275,-1.295,-1.3,-1.29,-1.305,-1.345,-1.38,-1.41,-1.415,-1.385,-1.355,-1.38,-1.425,-1.445,-1.445,-1.425,-1.41,-1.435,-1.465,-1.47,-1.465,-1.46,-1.46,-1.455,-1.46,-1.475,-1.47,-1.465,-1.455,-1.465,-1.45,-1.415,-1.38,-1.36,-1.33,-1.315,-1.315,-1.295,-1.265,-1.22,-1.185,-1.165,-1.13,-1.115,-1.07,-1.01,-0.995,-0.97,-0.955,-0.945,-0.89,-0.86,-0.855,-0.835,-0.85,-0.84,-0.82,-0.8,-0.8,-0.815,-0.81,-0.81,-0.805,-0.79,-0.805,-0.82,-0.845,-0.83,-0.805,-0.795,-0.785,-0.8,-0.85,-0.875,-0.875,-0.85,-0.865,-0.875,-0.89,-0.9,-0.88,-0.87,-0.87,-0.87,-0.865,-0.83,-0.785,-0.735,-0.72,-0.73,-0.765,-0.775,-0.78,-0.795,-0.845,-0.905,-0.93,-0.91,-0.865,-0.825,-0.825,-0.85,-0.865,-0.825,-0.78,-0.72,-0.68,-0.66,-0.66,-0.64,-0.6,-0.57,-0.545,-0.535,-0.52,-0.515,-0.49,-0.495,-0.525,-0.55,-0.555,-0.56,-0.575,-0.61,-0.62,-0.625,-0.595,-0.555,-0.515,-0.495,-0.505,-0.5,-0.485,-0.505,-0.54,-0.6,-0.605,-0.575,-0.545,-0.52,-0.54,-0.56,-0.57,-0.595,-0.6,-0.61,-0.595,-0.61,-0.635,-0.665,-0.725,-0.8,-0.87,-0.92,-0.97,-1.015,-1.03,-1.015,-0.945,-0.86,-0.805,-0.725,-0.595,-0.42,-0.21,0.035,0.29,0.53,0.75,0.925,1.04,1.005,0.705,0.28,-0.135,-0.415,-0.55,-0.575,-0.625,-0.7,-0.765,-0.77,-0.725,-0.695,-0.71,-0.74,-0.78,-0.79,-0.765,-0.765,-0.795,-0.82,-0.835,-0.84,-0.8,-0.78,-0.77,-0.77,-0.775,-0.79,-0.77,-0.73,-0.715,-0.705,-0.705,-0.715,-0.715,-0.695,-0.645,-0.65,-0.7,-0.705,-0.685,-0.68,-0.67,-0.655,-0.68,-0.655,-0.625,-0.57,-0.55,-0.545,-0.56,-0.545,-0.51,-0.47,-0.46,-0.47,-0.48,-0.47,-0.435,-0.38,-0.36,-0.355,-0.355,-0.35,-0.315,-0.285,-0.285,-0.26,-0.26,-0.26,-0.23,-0.22,-0.23,-0.23,-0.24,-0.24,-0.235,-0.235,-0.24,-0.255,-0.275,-0.29,-0.315,-0.36,-0.37,-0.39,-0.425,-0.47,-0.495])
peaks, _ = find_peaks(x, prominence=1, width=20)
plt.plot(x, "-")
plt.plot(peaks, x[peaks], "o")
plt.show()
```

## find_peaks-CPP:

```cpp
#include "find_peaks.h"
#include "matplotlibcpp.h"
#include <vector>
#define PINF numeric_limits<double>::infinity()

using namespace std;

vector<double> x = {-1.22,-1.225,-1.24,-1.245,-1.225,-1.215,-1.23,-1.245,-1.245,-1.215,-1.19,-1.185,-1.2,-1.205,-1.205,-1.195,-1.18,-1.165,-1.15,-1.165,-1.135,-1.09,-1.09,-1.09,-1.095,-1.075,-1.025,-0.975,-0.92,-0.885,-0.845,-0.795,-0.73,-0.65,-0.545,-0.455,-0.41,-0.385,-0.36,-0.335,-0.25,-0.195,-0.145,-0.085,-0.01,0.045,0.135,0.195,0.225,0.25,0.25,0.225,0.185,0.13,0.09,0.045,0.015,0.,0.025,0.03,0.,-0.055,-0.075,-0.085,-0.085,-0.055,-0.06,-0.09,-0.14,-0.21,-0.305,-0.43,-0.575,-0.775,-0.955,-1.095,-1.21,-1.3,-1.37,-1.425,-1.435,-1.435,-1.455,-1.47,-1.51,-1.54,-1.56,-1.585,-1.57,-1.56,-1.55,-1.565,-1.595,-1.6,-1.605,-1.625,-1.635,-1.655,-1.655,-1.68,-1.67,-1.675,-1.695,-1.725,-1.735,-1.73,-1.74,-1.745,-1.745,-1.75,-1.755,-1.765,-1.76,-1.765,-1.785,-1.795,-1.815,-1.815,-1.825,-1.825,-1.835,-1.845,-1.855,-1.84,-1.815,-1.815,-1.83,-1.845,-1.82,-1.79,-1.765,-1.735,-1.745,-1.76,-1.76,-1.71,-1.685,-1.665,-1.665,-1.65,-1.625,-1.59,-1.53,-1.475,-1.455,-1.45,-1.44,-1.41,-1.36,-1.335,-1.34,-1.36,-1.35,-1.325,-1.3,-1.27,-1.255,-1.25,-1.23,-1.22,-1.21,-1.215,-1.225,-1.225,-1.23,-1.21,-1.2,-1.205,-1.21,-1.2,-1.2,-1.18,-1.17,-1.165,-1.185,-1.185,-1.19,-1.185,-1.155,-1.165,-1.165,-1.155,-1.17,-1.175,-1.16,-1.16,-1.17,-1.18,-1.175,-1.15,-1.13,-1.12,-1.125,-1.13,-1.14,-1.135,-1.11,-1.11,-1.11,-1.125,-1.12,-1.105,-1.1,-1.095,-1.1,-1.11,-1.125,-1.115,-1.08,-1.06,-1.075,-1.08,-1.085,-1.075,-1.06,-1.05,-1.06,-1.08,-1.08,-1.055,-1.065,-1.055,-1.055,-1.065,-1.065,-1.06,-1.045,-1.04,-1.035,-1.045,-1.055,-1.04,-1.025,-1.02,-1.02,-1.045,-1.05,-1.03,-1.01,-0.99,-0.98,-0.98,-0.965,-0.945,-0.925,-0.905,-0.91,-0.915,-0.89,-0.87,-0.87,-0.845,-0.84,-0.855,-0.86,-0.865,-0.845,-0.84,-0.855,-0.885,-0.9,-0.91,-0.925,-0.95,-0.97,-0.995,-1.015,-1.01,-0.995,-0.995,-1.02,-1.03,-1.025,-1.01,-1.02,-1.03,-1.03,-1.045,-1.03,-1.02,-1.01,-1.005,-1.02,-1.03,-1.035,-1.025,-1.01,-1.015,-1.02,-1.04,-1.03,-1.03,-1.,-0.98,-0.925,-0.845,-0.71,-0.52,-0.27,0.005,0.26,0.455,0.555,0.49,0.245,-0.115,-0.495,-0.82,-0.955,-0.97,-0.97,-0.985,-1.01,-1.01,-0.975,-0.94,-0.945,-0.97,-1.,-1.,-0.985,-0.965,-0.95,-0.975,-0.98,-0.995,-0.995,-0.995,-0.97,-0.94,-0.945,-0.985,-0.98,-0.975,-0.98,-0.98,-0.965,-0.955,-0.95,-0.955,-0.94,-0.925,-0.905,-0.915,-0.91,-0.905,-0.9,-0.885,-0.89,-0.905,-0.905,-0.875,-0.87,-0.87,-0.87,-0.865,-0.85,-0.82,-0.8,-0.775,-0.785,-0.8,-0.815,-0.8,-0.755,-0.735,-0.73,-0.735,-0.74,-0.705,-0.67,-0.655,-0.66,-0.67,-0.675,-0.66,-0.635,-0.61,-0.59,-0.595,-0.595,-0.59,-0.57,-0.565,-0.58,-0.595,-0.585,-0.56,-0.52,-0.515,-0.51,-0.535,-0.56,-0.57,-0.575,-0.57,-0.575,-0.595,-0.625,-0.64,-0.605,-0.62,-0.655,-0.72,-0.745,-0.74,-0.71,-0.705,-0.745,-0.795,-0.825,-0.81,-0.82,-0.8,-0.825,-0.845,-0.875,-0.895,-0.875,-0.86,-0.86,-0.855,-0.84,-0.84,-0.86,-0.89,-0.895,-0.905,-0.875,-0.845,-0.84,-0.865,-0.89,-0.91,-0.91,-0.9,-0.885,-0.895,-0.875,-0.855,-0.87,-0.875,-0.875,-0.86,-0.85,-0.865,-0.85,-0.83,-0.815,-0.815,-0.835,-0.835,-0.845,-0.825,-0.81,-0.795,-0.795,-0.77,-0.75,-0.725,-0.71,-0.7,-0.715,-0.705,-0.71,-0.72,-0.7,-0.695,-0.7,-0.72,-0.715,-0.73,-0.735,-0.75,-0.78,-0.82,-0.815,-0.825,-0.825,-0.82,-0.835,-0.865,-0.87,-0.87,-0.875,-0.875,-0.875,-0.87,-0.87,-0.87,-0.875,-0.88,-0.875,-0.865,-0.865,-0.845,-0.845,-0.84,-0.85,-0.855,-0.86,-0.86,-0.88,-0.92,-0.94,-0.915,-0.825,-0.705,-0.55,-0.385,-0.215,0.,0.265,0.51,0.69,0.74,0.605,0.265,-0.095,-0.405,-0.66,-0.795,-0.85,-0.87,-0.875,-0.88,-0.83,-0.81,-0.81,-0.83,-0.84,-0.83,-0.825,-0.83,-0.86,-0.91,-0.915,-0.9,-0.865,-0.83,-0.85,-0.87,-0.87,-0.85,-0.82,-0.815,-0.83,-0.845,-0.85,-0.83,-0.805,-0.785,-0.785,-0.78,-0.76,-0.745,-0.725,-0.73,-0.73,-0.73,-0.735,-0.715,-0.705,-0.68,-0.68,-0.69,-0.68,-0.635,-0.625,-0.62,-0.61,-0.58,-0.57,-0.545,-0.53,-0.52,-0.52,-0.53,-0.525,-0.485,-0.45,-0.44,-0.445,-0.445,-0.44,-0.41,-0.375,-0.36,-0.375,-0.385,-0.395,-0.365,-0.35,-0.355,-0.39,-0.44,-0.45,-0.46,-0.425,-0.4,-0.425,-0.445,-0.465,-0.47,-0.495,-0.49,-0.53,-0.55,-0.54,-0.535,-0.545,-0.58,-0.62,-0.645,-0.655,-0.65,-0.655,-0.655,-0.655,-0.665,-0.68,-0.685,-0.685,-0.7,-0.7,-0.715,-0.72,-0.71,-0.68,-0.675,-0.675,-0.685,-0.69,-0.675,-0.675,-0.655,-0.675,-0.68,-0.67,-0.66,-0.66,-0.665,-0.685,-0.7,-0.705,-0.7,-0.685,-0.695,-0.7,-0.69,-0.695,-0.68,-0.655,-0.645,-0.64,-0.625,-0.62,-0.615,-0.6,-0.57,-0.545,-0.525,-0.535,-0.52,-0.49,-0.455,-0.465,-0.485,-0.49,-0.465,-0.435,-0.425,-0.405,-0.38,-0.32,-0.27,-0.18,-0.12,-0.08,-0.045,0.025,0.12,0.195,0.28,0.345,0.415,0.49,0.57,0.65,0.73,0.8,0.825,0.79,0.73,0.675,0.66,0.63,0.57,0.52,0.49,0.475,0.445,0.385,0.345,0.285,0.255,0.26,0.255,0.21,0.14,0.06,-0.025,-0.135,-0.275,-0.48,-0.67,-0.8,-0.885,-0.945,-0.965,-0.99,-1.01,-1.05,-1.07,-1.065,-1.07,-1.105,-1.14,-1.175,-1.165,-1.155,-1.175,-1.18,-1.205,-1.225,-1.22,-1.225,-1.235,-1.26,-1.275,-1.295,-1.3,-1.29,-1.305,-1.345,-1.38,-1.41,-1.415,-1.385,-1.355,-1.38,-1.425,-1.445,-1.445,-1.425,-1.41,-1.435,-1.465,-1.47,-1.465,-1.46,-1.46,-1.455,-1.46,-1.475,-1.47,-1.465,-1.455,-1.465,-1.45,-1.415,-1.38,-1.36,-1.33,-1.315,-1.315,-1.295,-1.265,-1.22,-1.185,-1.165,-1.13,-1.115,-1.07,-1.01,-0.995,-0.97,-0.955,-0.945,-0.89,-0.86,-0.855,-0.835,-0.85,-0.84,-0.82,-0.8,-0.8,-0.815,-0.81,-0.81,-0.805,-0.79,-0.805,-0.82,-0.845,-0.83,-0.805,-0.795,-0.785,-0.8,-0.85,-0.875,-0.875,-0.85,-0.865,-0.875,-0.89,-0.9,-0.88,-0.87,-0.87,-0.87,-0.865,-0.83,-0.785,-0.735,-0.72,-0.73,-0.765,-0.775,-0.78,-0.795,-0.845,-0.905,-0.93,-0.91,-0.865,-0.825,-0.825,-0.85,-0.865,-0.825,-0.78,-0.72,-0.68,-0.66,-0.66,-0.64,-0.6,-0.57,-0.545,-0.535,-0.52,-0.515,-0.49,-0.495,-0.525,-0.55,-0.555,-0.56,-0.575,-0.61,-0.62,-0.625,-0.595,-0.555,-0.515,-0.495,-0.505,-0.5,-0.485,-0.505,-0.54,-0.6,-0.605,-0.575,-0.545,-0.52,-0.54,-0.56,-0.57,-0.595,-0.6,-0.61,-0.595,-0.61,-0.635,-0.665,-0.725,-0.8,-0.87,-0.92,-0.97,-1.015,-1.03,-1.015,-0.945,-0.86,-0.805,-0.725,-0.595,-0.42,-0.21,0.035,0.29,0.53,0.75,0.925,1.04,1.005,0.705,0.28,-0.135,-0.415,-0.55,-0.575,-0.625,-0.7,-0.765,-0.77,-0.725,-0.695,-0.71,-0.74,-0.78,-0.79,-0.765,-0.765,-0.795,-0.82,-0.835,-0.84,-0.8,-0.78,-0.77,-0.77,-0.775,-0.79,-0.77,-0.73,-0.715,-0.705,-0.705,-0.715,-0.715,-0.695,-0.645,-0.65,-0.7,-0.705,-0.685,-0.68,-0.67,-0.655,-0.68,-0.655,-0.625,-0.57,-0.55,-0.545,-0.56,-0.545,-0.51,-0.47,-0.46,-0.47,-0.48,-0.47,-0.435,-0.38,-0.36,-0.355,-0.355,-0.35,-0.315,-0.285,-0.285,-0.26,-0.26,-0.26,-0.23,-0.22,-0.23,-0.23,-0.24,-0.24,-0.235,-0.235,-0.24,-0.255,-0.275,-0.29,-0.315,-0.36,-0.37,-0.39,-0.425,-0.47,-0.495};
vector<int> index;
for (int i = 0; i < x.size(); i++) {
  index.push_back(i);
}
vector<int> peakIndex = findPeaks(x, {}, {}, {}, 0, {1.0, PINF}, -1, {20.0, PINF}, 0.5);  //x, plateauSize, height, threshold, distance, prominence, wlen, width, relHeight
vector<double> peak;
for (int i = 0; i < peakIndex.size(); i++) {
  peak.push_back(x[peakIndex[i]]);
}
//plotXYs is a function that uses 'matplotlib', we dont't show the code here
plotXYs({ index, peakIndex }, { x, peak }, { "g-", "ro"}, { 1200, 780 });
```
