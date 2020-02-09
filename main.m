testimage = linspace(1,256,128);
for i = 1:5
    testimage = [testimage;linspace(1,256,128);];
end
% 
testimage = imread('beach.bmp');
colormap(gray)
redChannel = testimage(:,:,1);
imagesc(redChannel);



figure(1)

dlmwrite('testimage.dat',redChannel,'delimiter',' ','newline','pc');

%system('.\Negative.exe'); 

figure(2)
B = load('result.dat');
C = load('histogram.dat');

colormap(gray)
imagesc(B)
figure(3)
bar(C);