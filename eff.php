<html>
  <head>
    <title>
      Quarkonia efficiencies
    </title>
    <style type='text/css'>
      div.pic {
      display: block;
      float: left;
      background-color: white;
      border: 1px solid #ccc;
      padding: 2px;
      text-align: center;
      margin: 2px 10px 10px 2px;
      -moz-box-shadow: 7px 5px 5px rgb(80,80,80);    /* Firefox 3.5 */
      -webkit-box-shadow: 7px 5px 5px rgb(80,80,80); /* Chrome, Safari */
      box-shadow: 7px 5px 5px rgb(80,80,80);         /* New browsers */
      }
    </style>
  </head>
  <body>

    <?php
       $dirname = "cms/quarkonia/MC/eff/";
       $images = glob($dirname."*.png");

       foreach($images as $image) {
       $path_parts = pathinfo($image);
       $filename = $path_parts['dirname']."/".$path_parts['filename'];
       $filenamepng = $filename.".png";
       $filenamepdf = $filename.".pdf";
       $filenameroot = $path_parts['filename'].".root";
       echo '<div class="pic"><a href="'.$filenamepdf.'"><img src="'.$filenamepng.'"></a><br><a href="'.$filenameroot.'">'.$filenameroot.'</a></div>', "\n";

       }
       ?>
  </body>
</html>
