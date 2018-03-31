clear;
close all;
x=cell(20,1);
for i=1:10
a=audioread(['/Users/zhouxin/Desktop/…˘“Ù∑÷¿‡/±¨’®…˘“Ù/' num2str(i) '.mp3']);
b=size(a);

if b(2)>1
    z=a(:,1);
else
    z=a;
end
z=z';
x{i,1}=z;
end

for i=1:10
a=audioread(['/Users/zhouxin/Desktop/…˘“Ù∑÷¿‡/∆˚≥µ¿Æ∞»…˘/' num2str(i) '.mp3']);
b=size(a);

if b(2)>1
    z=a(:,1);
else
    z=a;
end
z=z';
x{i+10,1}=z;
end

y(20,1)=0;
for i=1:10
    y(i)=1;
end

for i=11:20
    y(i)=2;
end

inputSize = 1;
outputSize = 10;
outputMode = 'last';
numClasses = 2;

layers = [ ...
    sequenceInputLayer(inputSize)
    lstmLayer(outputSize,'OutputMode',outputMode)
    fullyConnectedLayer(numClasses)
    softmaxLayer
    classificationLayer];

maxEpochs = 150;
miniBatchSize = 27;
shuffle = 'never';

options = trainingOptions('sgdm', ...
    'MaxEpochs',maxEpochs, ...
    'MiniBatchSize',miniBatchSize, ...
    'Shuffle', shuffle);

maxEpochs = 150;
miniBatchSize = 27;
shuffle = 'never';

options = trainingOptions('sgdm', ...
    'MaxEpochs',maxEpochs, ...
    'MiniBatchSize',miniBatchSize, ...
    'Shuffle', shuffle);

net = trainNetwork(x,y,layers,options);
% for j=1:10
%    x=audioread(['/Users/zhouxin/Desktop/…˘“Ù∑÷¿‡/±¨’®…˘“Ù/' num2str(j) '.mp3']);
% end