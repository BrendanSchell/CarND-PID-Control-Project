# Project 9 - PID Controller in C++

## Describe the effect each of the P, I, D components had in your implementation.

The P component provides a steering angle response that is proportional to the value of the cross-track error. When a value of 0.2 is used for the P coefficient, it can be seen that the car responds to the cross track error by swaying to the left or right. This response on its own overshoots the desired behaviour and results in larger and larger oscillations.

The D component provides an additional response that is proportional to the change in the value of the cross-track error. When a value of 3 is chosen for the D coefficient, it can be seen that the oscillations are no longer increasing and the car stays within the limits of the track.

The I component provides an additional response that is proportional to the integrated value of the cross-track error. When a value of 0.01 is used, the bias of the steering is overcome and the car no longer has less of a preference to veer right.

## Describe how the final hyperparameters were chosen.

The final hyperparameters were chosen in an iterative manner. I started by setting all PID coefficients to a value of 0. With this version of the PID, the car would drive completely straight with no error response. 

[No Controller](https://youtu.be/iu7LkELocBg)

I then increased the P component until it demonstrated a significant response to the cross-track error. A value of 0.2 was sufficient. 

[P Controller Only](https://youtu.be/hltDnF9vOcU)


With this value for the P component, the oscillations of the car increase over time. To combat this, I increased the D component of the PID until the oscillations were manageable and the car did not go outside the track. A value of 3.0 was used for the D component.

[PD Controller Only](https://youtu.be/z52d4O9o2AEU)

I then incremented the I component to make the responses a little smoother. A value of 0.001 was sufficient to smooth the response without causing performance to decrease. The final performance can be seen below.

[Final PID Controller](https://youtu.be/QRBpIXL-tLI)


