<?php

/**
 * Implementation of hook_rules_defaults().
 */
function transition_alert_web_contacts_rules_defaults() {
  module_load_include('inc', 'transition_alert_web_contacts', 'transition_alert_web_contacts.defaults');
  $args = func_get_args();
  return call_user_func_array('_transition_alert_web_contacts_rules_defaults', $args);
}
