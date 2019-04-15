%% set parameters
filePath = 'D:\576 Data\dataset\Videos\data_test1.wav';
seconds = 5*60;
detWindowLen = 100;

%% load audio
audio = audioread(filePath);
sampleCount= size(audio,1);
frequency = sampleCount/seconds;

%% detection
subAudioCount = 0;
lastIndex = 1;
subAudio = {};
for i = 1:1:sampleCount/detWindowLen
  sum = 0;
  for j = 1:1:detWindowLen
    sum += audio(detWindowLen*i+j);
  endfor
  avg = sum / detWindowLen;
  if (avg < 0.0005)
    subAudioCount++;
    subAudio(:,subAudioCount) = audio(lastIndex:detWindowLen*i);
  endif
endfor
