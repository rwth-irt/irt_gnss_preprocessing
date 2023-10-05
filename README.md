# IRT GNSS Pre-Processing

This is the official package of irt_gnss_preprocessing. The package provide a ros wrapper and sevral interfaces of popular GNSS receivers to GNSS pre-processing algorithms and modules. 

The package is designed with the concept of pluginlib. The interface to each receiver is implemented as a plugin so that it can be configured in the configuration file. 

The details of processing logics and algorithms will be updated later. 

### Currently, only ROS2 is supported, the ROS1 version is in development.

---

## Suported GNSS Receivers:
1. Novatel OEM7
2. Ublox F9P (still in progress)

---

## How to start
```
ros2 launch irt_gnss_preprocessing gnss_preprocessor.launch.py 
```

## Papers using this package 
[1] *Haoming Zhang, Chih-Chun Chen, Heike Vallery and Timothy D. Barfoot*, GNSS/Multi-Sensor Fusion Using Continuous-Time Factor Graph Optimization for Robust Localization, submitted to IEEE T-TRO, arxiv, DOI: [10.48550/arXiv.2309.11134](https://doi.org/10.48550/arXiv.2309.11134)

[2] *Haoming Zhang, Zhanxin Wang and Heike Vallery*, Learning-based NLOS Detection and Uncertainty Prediction of GNSS Observations with Transformer-Enhanced LSTM Network, accepted for the IEEE ITSC2023, arxiv, DOI: [10.48550/arXiv.2309.00480](https://doi.org/10.48550/arXiv.2309.00480)

[3] *Haoming Zhang, Xiao Xia, Maximilian Nitsch and Dirk Abel*, Continuous-Time Factor Graph Optimization for Trajectory Smoothness of GNSS/INS Navigation in Temporarily GNSS-Denied Environments, IEEE Robotics and Automation Letters (RAL), DOI: [10.1109/LRA.2022.3189824](https://doi.org/10.1109/LRA.2022.3189824


---

## ToDos:
1. generate wiki for GNSS algorithms
2. generate wiki for parameters in the config file
3. test ublox interface