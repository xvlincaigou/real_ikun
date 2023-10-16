import cv2
import os
 
def video2image(video_dir,save_dir):
    cap = cv2.VideoCapture(video_dir) 
    n = 1     
    fps = cap.get(cv2.CAP_PROP_FPS)   
    i = 0
    timeF = int(fps) / 10    
    while cap.isOpened():
        ret,frame = cap.read()
        if ret is False :
            break
        if (n % timeF == 0) :
            i += 1
            print('保存第 %s 张图像' % i)
            save_image_dir = os.path.join(save_dir,'%s.jpg' % i)
            print('save_image_dir: ', save_image_dir)
            cv2.imwrite(save_image_dir,frame) 
        n = n + 1
        cv2.waitKey(1)
    cap.release()
 
 
if __name__ == '__main__' :
    video2image(r"E:\study\python\20231016_190819.mp4", r"E:\study\python\out")