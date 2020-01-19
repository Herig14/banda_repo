var dat = []
var chart
var validos = 0
var defectuosos = 0
window.onload = function() {
    this.UpdateJson()
    temp =[{name:"Correctos", y:this.validos},{name:"Dfectuosos", y:this.defectuosos} ]
     chart = Highcharts.chart('container', {
        chart: {
            type: 'pie'
        },
    
        series: [{
            data: temp
        }]
    });
  };



// the button action
var tid = setInterval(test, 2000);
function test() {
    UpdateJson()
    temp =[{name:"Correctos", y:this.validos},{name:"Dfectuosos", y:this.defectuosos} ]
    console.log(validos)
        chart.series[0].setData(temp);  
}

/*var datos = Highcharts.chart('container',{
    //////////////////////////1////////////////////////
    chart: {
        plotBackgroundColor: null,
        plotBorderWidth: null,
        plotShadow: false,
        type: 'pie'
    },
    title: {
        text: 'Cantidad de objetos detectados'
    },
    plotOptions: {
        pie: {
            allowPointSelect: true,
            cursor: 'pointer',
            dataLabels: {
                enabled: true
            }
        }
    },
    series: [{
        name: 'Brands',
        colorByPoint: true,
        data: []
    }]})*/

    //Highcharts.chart('container', datos)
//var tid = setInterval(mycode, 2000);
function UpdateJson() {
  console.log("hola")
  $.getJSON( "/json/datos.json", function( json ) {
    //console.log( "JSON Data: " + json[0].objeto);
    //temp =[{name:"Correctos", y:0},{name:"Dfectuosos", y:0} ]
    y1=0
    y2=0
    for (i in json){
        if(json[i].objeto==1){
            y1++
        }else{
            y2++
        }
    }
    setData(y1,y2)
   // console.log(json)
   });
}
function setData(y1,y2){
    validos = y1
    defectuosos = y2
    console.log(y1)
    console.log(y2)
}