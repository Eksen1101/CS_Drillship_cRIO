<portlist>
<inport> Id = "1"  Name = "Input to model" Width = "1" DataType = "real_T" </inport>
<inport> Id = "2"  Name = "x_ref" Width = "1" DataType = "real_T" </inport>
<inport> Id = "3"  Name = "y_ref" Width = "1" DataType = "real_T" </inport>
<inport> Id = "4"  Name = "Input1/reset" Width = "1" DataType = "real_T" </inport>
<inport> Id = "5"  Name = "eta_QTM/x_m" Width = "1" DataType = "real_T" </inport>
<inport> Id = "6"  Name = "eta_QTM/y_m" Width = "1" DataType = "real_T" </inport>
<inport> Id = "7"  Name = "eta_QTM/psi_m" Width = "1" DataType = "real_T" </inport>
<inport> Id = "8"  Name = "psi_ref [deg]" Width = "1" DataType = "real_T" </inport>
<inport> Id = "9"  Name = "Control/alpha_u" Width = "1" DataType = "real_T" </inport>
<inport> Id = "10"  Name = "Control/K1_u" Width = "1" DataType = "real_T" </inport>
<inport> Id = "11"  Name = "Control/K1_r" Width = "1" DataType = "real_T" </inport>
<inport> Id = "12"  Name = "Control/alpha_r" Width = "1" DataType = "real_T" </inport>
<inport> Id = "13"  Name = "IMU/Acc_x" Width = "1" DataType = "real_T" </inport>
<inport> Id = "14"  Name = "IMU/Acc_y" Width = "1" DataType = "real_T" </inport>
<inport> Id = "15"  Name = "IMU/Acc_z" Width = "1" DataType = "real_T" </inport>
<inport> Id = "16"  Name = "IMU/Gyro_x" Width = "1" DataType = "real_T" </inport>
<inport> Id = "17"  Name = "IMU/Gyro_y" Width = "1" DataType = "real_T" </inport>
<inport> Id = "18"  Name = "IMU/Gyro_z" Width = "1" DataType = "real_T" </inport>
<inport> Id = "19"  Name = "Input1/Control Gains/K_p_x" Width = "1" DataType = "real_T" </inport>
<inport> Id = "20"  Name = "Input1/Control Gains/K_p_y" Width = "1" DataType = "real_T" </inport>
<inport> Id = "21"  Name = "Input1/Control Gains/K_p_psi" Width = "1" DataType = "real_T" </inport>
<inport> Id = "22"  Name = "Input1/Control Gains/K_i_psi" Width = "1" DataType = "real_T" </inport>
<inport> Id = "23"  Name = "Input1/Control Gains/K_i_x" Width = "1" DataType = "real_T" </inport>
<inport> Id = "24"  Name = "Input1/Control Gains/K_i_y" Width = "1" DataType = "real_T" </inport>
<inport> Id = "25"  Name = "Input1/Control Gains/K_d_psi" Width = "1" DataType = "real_T" </inport>
<inport> Id = "26"  Name = "Input1/Control Gains/K_d_x" Width = "1" DataType = "real_T" </inport>
<inport> Id = "27"  Name = "Input1/Control Gains/K_d_y" Width = "1" DataType = "real_T" </inport>
<inport> Id = "28"  Name = "Input1/Guidance gains/w_d_x" Width = "1" DataType = "real_T" </inport>
<inport> Id = "29"  Name = "Input1/Guidance gains/w_d_y" Width = "1" DataType = "real_T" </inport>
<inport> Id = "30"  Name = "Input1/Guidance gains/w_d_psi" Width = "1" DataType = "real_T" </inport>
<inport> Id = "31"  Name = "Input1/Guidance gains/zeta_psi" Width = "1" DataType = "real_T" </inport>
<inport> Id = "32"  Name = "Input1/Guidance gains/zeta_x" Width = "1" DataType = "real_T" </inport>
<inport> Id = "33"  Name = "Input1/Guidance gains/zeta_y" Width = "1" DataType = "real_T" </inport>
<outport> Id = "1"  Name = "Output to Workspace" Width = "1" DataType = "real_T" </outport>
<outport> Id = "2"  Name = "x_t" Width = "1" DataType = "real_T" </outport>
<outport> Id = "3"  Name = "y_t" Width = "1" DataType = "real_T" </outport>
<outport> Id = "4"  Name = "Observer output /eta_hat output/x_hat" Width = "1" DataType = "real_T" </outport>
<outport> Id = "5"  Name = "Observer output /eta_hat output/y_hat" Width = "1" DataType = "real_T" </outport>
<outport> Id = "6"  Name = "Observer output /eta_hat output/psi_hat" Width = "1" DataType = "real_T" </outport>
<outport> Id = "7"  Name = "Observer output /nu_hat output/u_hat" Width = "1" DataType = "real_T" </outport>
<outport> Id = "8"  Name = "Observer output /nu_hat output/v_hat" Width = "1" DataType = "real_T" </outport>
<outport> Id = "9"  Name = "Observer output /nu_hat output/r_hat" Width = "1" DataType = "real_T" </outport>
<outport> Id = "10"  Name = "Observer output /nu_dot_hat output/u_dot_hat" Width = "1" DataType = "real_T" </outport>
<outport> Id = "11"  Name = "Observer output /nu_dot_hat output/v_dot_hat" Width = "1" DataType = "real_T" </outport>
<outport> Id = "12"  Name = "Observer output /nu_dot_hat output/r_dot_hat" Width = "1" DataType = "real_T" </outport>
<outport> Id = "13"  Name = "Observer output /b_hat output/b_x_hat" Width = "1" DataType = "real_T" </outport>
<outport> Id = "14"  Name = "Observer output /b_hat output/b_y_hat" Width = "1" DataType = "real_T" </outport>
<outport> Id = "15"  Name = "Observer output /b_hat output/b_psi_hat" Width = "1" DataType = "real_T" </outport>
<outport> Id = "16"  Name = "Output/alpha1" Width = "1" DataType = "real_T" </outport>
<outport> Id = "17"  Name = "Output/alpha2" Width = "1" DataType = "real_T" </outport>
<outport> Id = "18"  Name = "Output/alpha3" Width = "1" DataType = "real_T" </outport>
<outport> Id = "19"  Name = "Output/alpha4" Width = "1" DataType = "real_T" </outport>
<outport> Id = "20"  Name = "Output/alpha5" Width = "1" DataType = "real_T" </outport>
<outport> Id = "21"  Name = "Output/alpha6" Width = "1" DataType = "real_T" </outport>
<outport> Id = "22"  Name = "Output/u1" Width = "1" DataType = "real_T" </outport>
<outport> Id = "23"  Name = "Output/u2" Width = "1" DataType = "real_T" </outport>
<outport> Id = "24"  Name = "Output/u3" Width = "1" DataType = "real_T" </outport>
<outport> Id = "25"  Name = "Output/u4" Width = "1" DataType = "real_T" </outport>
<outport> Id = "26"  Name = "Output/u5" Width = "1" DataType = "real_T" </outport>
<outport> Id = "27"  Name = "Output/u6" Width = "1" DataType = "real_T" </outport>
<outport> Id = "28"  Name = "psi_t" Width = "1" DataType = "real_T" </outport>
</portlist>
