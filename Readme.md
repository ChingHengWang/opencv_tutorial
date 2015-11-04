# opencv_tutorial


* install opencv on Ubuntu follow this step

		http://docs.opencv.org/2.4/doc/tutorials/introduction/linux_install/linux_install.html

* tutorial follow this website

		http://wiki.opencv.org.cn/index.php/Template:Code

open figure - display_image
* first step : imread the image to Mat format variable
		
		Mat image = imread("me.jpg");

* second step :  show the image on window

		namedWindow("Display Image", WINDOW_AUTOSIZE );

		imshow("Display Image", image);


save figure -copy_save_image

		imwrite("haha.jpg",image);

