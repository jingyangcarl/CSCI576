%% set parameters
filePath = 'D:\576 Data\dataset\Videos\data_test1.wav';
seconds = 5*60;
intervalLen = 3;
singlePlot = 0;

%% load audio
audio = audioread(filePath);
sampleCount= size(audio,1);
frequency = sampleCount/seconds;

% retrieve quantized audio
audio = audio .* 2^15;

%% Cuts
% The 1st scene cut is at 20s in the video
% Border shape: triangle
cutPos_1 = 20;
audioCut_1 = audio((cutPos_1-intervalLen)*frequency:(cutPos_1+intervalLen)*frequency);
if (singlePlot == 1)
  figure(1);
elseif (singlePlot == 0)
  subplot(5, 2, 1)
endif
plot(audioCut_1);

% The 2nd scene cut is at 39s in the video
% Border shape: triangle
cutPos_2 = 39;
audioCut_2 = audio((cutPos_2-intervalLen)*frequency:(cutPos_2+intervalLen)*frequency);
if (singlePlot == 1)
  figure(2);
elseif (singlePlot == 0)
  subplot(5, 2, 2)
endif
plot(audioCut_2);

% The 3rd scene cut is at 80s in the video, which is the start point of an ad
% Border shape: cut
cutPos_3 = 80;
audioCut_3 = audio((cutPos_3-intervalLen)*frequency:(cutPos_3+intervalLen)*frequency);
if (singlePlot == 1)
  figure(3);
elseif (singlePlot == 0)
  subplot(5, 2, 3)
endif
plot(audioCut_3);

% The 4th scene cut is at 95s in the video, which is the end point of the ad
% Border shape: cut
cutPos_4 = 95;
audioCut_4 = audio((cutPos_4-intervalLen)*frequency:(cutPos_4+intervalLen)*frequency);
if (singlePlot == 1)
  figure(4);
elseif (singlePlot == 0)
  subplot(5, 2, 4)
endif
plot(audioCut_4);

% The 5th scene cut is at 120s in the video
% Border shape: not obvious
cutPos_5 = 120;
audioCut_5 = audio((cutPos_5-intervalLen)*frequency:(cutPos_5+intervalLen)*frequency);
if (singlePlot == 1)
  figure(5);
elseif (singlePlot == 0)
  subplot(5, 2, 5)
endif
plot(audioCut_5);

% The 6th scene cut is at 145s in the video
% Border shape: triangle
cutPos_6 = 145;
audioCut_6 = audio((cutPos_6-intervalLen)*frequency:(cutPos_6+intervalLen)*frequency);
if (singlePlot == 1)
  figure(6);
elseif (singlePlot == 0)
  subplot(5, 2, 6)
endif
plot(audioCut_6);

% The 7th scene cut is at 185s in the video, which is the start point of an ad
% Border shape: cut
cutPos_7 = 185;
audioCut_7 = audio((cutPos_7-intervalLen)*frequency:(cutPos_7+intervalLen)*frequency);
if (singlePlot == 1)
  figure(7);
elseif (singlePlot == 0)
  subplot(5, 2, 7)
endif
plot(audioCut_7);

% The 8th scene cut is at 200s in the video, which is the end point of an ad
% Border shape: not obvious
cutPos_8 = 200;
audioCut_8 = audio((cutPos_8-intervalLen)*frequency:(cutPos_8+intervalLen)*frequency);
if (singlePlot == 1)
  figure(8);
elseif (singlePlot == 0)
  subplot(5, 2, 8)
endif
plot(audioCut_8);

% The 9th scene cut is at 215s in the video
% Border shape: triangle
cutPos_9 = 215;
audioCut_9 = audio((cutPos_9-intervalLen)*frequency:(cutPos_9+intervalLen)*frequency);
if (singlePlot == 1)
  figure(9);
elseif (singlePlot == 0)
  subplot(5, 2, 9)
endif
plot(audioCut_9);

% The 10th scene cut is at 240s in the video
% Border shape: triangle
cutPos_10 = 240;
audioCut_10 = audio((cutPos_10-intervalLen)*frequency:(cutPos_10+intervalLen)*frequency);
if (singlePlot == 1)
  figure(10);
elseif (singlePlot == 0)
  subplot(5, 2, 10)
endif
plot(audioCut_10);
