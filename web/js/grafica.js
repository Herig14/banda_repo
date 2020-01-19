var dat = []
var chart
var chart2
var validos = 0
var defectuosos = 0
var flag = 0
var upbol = true
window.onload = function() {
    UpdateJson()
    temp =[{name:"Correctos", y:this.validos},{name:"Defectuosos", y:this.defectuosos} ]
    console.log(temp)
    chart = Highcharts.chart('container', {
        chart: {
            type: 'pie'
        },
        title: {
            text: 'Correctos Vs Defectuosos'
        },    
        series: [{
            data: temp
        }]
    });
    chart2 = Highcharts.chart('container2', {
        chart: {
            type: 'column'
        },
        title: {
            text: 'Produccion'
        },
        xAxis: {
            categories: ['Esto', 'va', 'a', 'estar']
        }
        ,
        yAxis: {
            allowDecimals: false,
            min: 0,
            title: {
                text: 'Numero de unidades'
            }
        },
        plotOptions: {
            column: {
                stacking: 'normal',
                dataLabels: {
                    enabled: true
                }
            }
        },
        series: [{
            name: 'Correctos',
            data: [5, 3, 4, 7, 2]
        }, {
            name: 'Defectuosos',
            data: [2, 2, 3, 2, 1]
        }]
    });
  };

var tid = setInterval(test, 500);
var tid2 = setInterval(test2, 2000);
function test() {
    UpdateJson2()
    console.log("actu")
   if(upbol){
    temp =[{name:"Correctos", y:this.validos},{name:"Defectuosos", y:this.defectuosos} ]
    chart.series[0].setData(temp);
    upbol =false
    }
    /*
    validos = validos +Math.floor(Math.random() * 20);
    temp =[{name:"Correctos", y:this.validos},{name:"Defectuosos", y:this.defectuosos} ]
    chart.series[0].setData(temp);*/
}
function test2() {
    console.log("actu2")
   // chart2.series[0].addPoint(10);

    for (i in chart2.series){
        chart2.series[i].addPoint(Math.floor(Math.random() * 15));
        chart2.series[i].data[0].remove();
    }
  //  chart2.xAxis[0].update({categories:['Esto', 'va', 'a', 'estar', 'o no']}, true);
 // chart2.xAxis[0].setCategories(['', 'F', 'M', 'A', 'M', 'J', 'J', 'A', 'S', 'O', 'N', 'D']);
}
function UpdateJson() {
  console.log("hola")
  $.getJSON( "/json/datos.json", function( json ) {
    y1=0
    y2=0
    for (i in json){
        if(json[i].objeto==1){
            y1++
        }else{
            y2++
        }
    }
    setData(y1,y2,Object.keys(json).length)
   });
}
function UpdateJson2() {
   // console.log("hola")
    $.getJSON( "/json/datos.json", function( json ) {
      y1=validos
      y2=defectuosos
      T = Object.keys(json).length
      for (var i = flag; i < T; i++){
          console.log("Hola")
          upbol = true;
          if(json[i].objeto==1){
              y1++
          }else{
              y2++
          }
      }
      
      setData(y1,y2,T)
     });
  }
function setData(y1,y2,b){
    validos = y1
    defectuosos = y2
    flag = b
}