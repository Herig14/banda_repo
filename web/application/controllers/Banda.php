<?php
class Banda extends CI_Controller {
        public function index()
        {
                $this->load->helper('url');
                $this->load->helper('html');
                /*$data['news'] = $this->news_model->get_news();*/
                $data['title'] = 'TItulo temp';

                $this->load->view('banda/templates/header', $data);
                $this->load->view('banda/home', $data);
                $this->load->view('banda/templates/footer');
        }
        public function read_db()
        {
                $this->load->helper('url');
                $this->load->helper('html');
                /*$data['news'] = $this->news_model->get_news();*/
                $data['title'] = 'TItulo temp';

                $this->load->view('banda/templates/header', $data);
                $this->load->view('banda/read_db', $data);
                $this->load->view('banda/templates/footer');
        }
        public function insertdb()
        {
                $this->load->helper('url');
                $this->load->helper('html');
                /*$data['news'] = $this->news_model->get_news();*/
                $data['title'] = 'TItulo temp';

                $this->load->view('banda/templates/header', $data);
                $this->load->view('banda/InsertDB', $data);
                $this->load->view('banda/templates/footer');
        }

/*         public function view($page = 'home')
        {
                if ( ! file_exists(APPPATH.'views/banda/'.$page.'.php'))
        {
                // Whoops, we don't have a page for that!
                show_404();
        }

        $data['title'] = ucfirst($page); // Capitalize the first letter

        $this->load->view('templates/header', $data);
        $this->load->view('banda/'.$page, $data);
        $this->load->view('templates/footer', $data);
        } */
}
 
