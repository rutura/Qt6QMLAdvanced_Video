import QtQuick

Item {
    Canvas{
        id: root
        width: 300
        height: 300

        onPaint: function(){
            //Do the drawing
            var context = getContext("2d");
            context.reset();

            //Move the pin of the pen to the center
            var centerX = width/2
            var centerY = height/2

            //Draw the path
            context.beginPath()
            context.fillStyle = "yellowgreen"
            context.moveTo(centerX,centerY)
            context.arc(centerX,centerY,width/2,0,Math.PI * 1.5,false)
            context.lineTo(centerX,centerY)
            context.fill()

            context.beginPath();
            context.fillStyle = "red";
            context.moveTo(centerX, centerY);
            context.arc(centerX, centerY, width / 4, Math.PI *1.5, Math.PI, false);
            context.lineTo(centerX, centerY);
            context.fill();
        }
    }

}
