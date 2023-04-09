const PORT = process.env.PORT || 8080
const axios = require('axios') // https url access (like curl)
const cheerio = require('cheerio') // we scraper access classes
const fs = require('fs')
const express = require('express') // target url, to follow root
const app = express()
const cors = require('cors') // headers

const { compileFunction } = require('vm')
app.use(cors())
var len = 20;
async function gets(urls) {
    return await axios.get(urls) 
};
function SortByName(x, y) {
    return ((x.titles == y.titles) ? 0 : ((x.titles > y.titles) ? 1 : -1));
}

async function flipkart(product) {

    var art1 = []; 
    let url = `https://www.flipkart.com/search?q=${product}` // scraping url
    const resp = axios(url)
        .then(response => {
            const html = response.data
            const $ = cheerio.load(html)

            let site = "flipkart"
            let titles = []
            let prices = []
            let imgs = []
            let urls = []
            let mrps = []
            let specs = []
            let spectab = [];
            let tabledata = [];

            $('div._27UcVY', html).each(function () { mrps.push($(this).text().replace('₹', '')); })
            $('img._396cs4', html).each(function () { titles.push($(this).attr('alt')); })
            $('ul._1xgFaf', html).each(function () { specs.push($(this).text()); })
            $('div._30jeq3', html).each(function () { prices.push($(this).text().replace('₹', '')); })
            $('img._396cs4', html).each(function () { imgs.push($(this).attr('src')); })
            $('a._1fQZEK', html).each(function () { urls.push($(this).attr('href').replace(/^(\/)/, 'https://www.flipkart.com/').replace(/\?.*/, '')); })
            
            if (!urls.length) {
                $('a._2rpwqI', html).each(function () { urls.push($(this).attr('href').replace(/^(\/)/, 'https://www.flipkart.com/').replace(/\?.*/, '')); })
            }

             var re;
            if (!specs.length) {
                urls.forEach(element => {
                    re = await this.gets(element);
              });
            }
                
                console.log(`Spec: ${re.data}`);
            

            if (!mrps.length) {
                $('div._3I9_wc', html).each(function () { mrps.push($(this).text().replace('₹', '')); })
            }

            for (let i = 1; i < len; i++) {
                let title = titles[i]
                let url = urls[i]
                let img = imgs[i]
                let price = prices[i]
                let mrp = mrps[i]
                let spec = specs[i]

                art1.push({
                    site,
                    title,
                    price,
                    mrp,
                    url,
                    img,
                    spec,
                })
            }
            return art1;
        }).catch(err => console.log(err))
    return resp;
}


app.get('/results', async function (req, res) {

	const product = req.query.product.replace('_',' ');
	let result = []
	const r2 = await flipkart(product);
    console.log(r2)
	result = [r2];
	res.json(result);

})


app.listen(PORT, () => console.log(`server running on PORT ${PORT}`))

